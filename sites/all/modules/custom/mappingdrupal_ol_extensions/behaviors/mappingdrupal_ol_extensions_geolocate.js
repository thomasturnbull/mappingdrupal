/**
 * @file
 * JS Implementation of OpenLayers behavior for Geolocation.
 */

// Namespace $ to jQuery
(function($) {

/**
 * Geolocation Behavior
 */
Drupal.behaviors.mappingdrupal_ol_extensions_geolocate = {
  'attach': function(context, settings) {
    var data = $(context).data('openlayers');
    if (data && data.map.behaviors['mappingdrupal_ol_extensions_geolocate']) {
      // Data about the map configuration and the map itself are stored
      // with jQuery's .data() functionality on the element that
      // contains the map.
      //
      // You can access the following from the data variable:
      // - data.map: The map configuration object.
      // - data.openlayers: The OpenLayers map object.

      // This makes it easy to reference the local behavior options.
      var options = data.map.behaviors['mappingdrupal_ol_extensions_geolocate'];
      
      // First, check if the option to geolocate on load is
      // enabled.
      if (options.on_load) {
        Drupal.behaviors.mappingdrupal_ol_extensions_geolocate.geolocate(data.openlayers, options.zoom);
      }
      
      // Then check if a button was enabled.  We are utilizing
      // OpenLayers Button and Panels Controls for this, 
      // but this could be any sort of button.
      if (options.button) {
        var button = new OpenLayers.Control.Button({
          displayClass: 'mappingdrupal-ol-geolocate-button',
          title: Drupal.t('Geolocate'),
          trigger: function() {
            Drupal.behaviors.mappingdrupal_ol_extensions_geolocate.geolocate(data.openlayers, options.zoom);
          }
        });
        var panel = new OpenLayers.Control.Panel({
          displayClass: 'mappingdrupal-ol-geolocate-panel',
          defaultControl: button
        });
        panel.addControls([button]);
        data.openlayers.addControl(panel);
        panel.activate();
      }
    }
  },
  
  // General function to geolocate user.
  'geolocate': function(map, zoom) {
    // Firest ensure that that the HTML5 geolocation controls
    // are available.  We might use some more helpful
    // libraries for this, like Modernizr
    //
    // We have to make sure we are explicit of the projection
    // as latitude and longitude are different from
    // spherical mercator (or other possiblilities).
    if (typeof navigator != 'undefined' && typeof navigator.geolocation != 'undefine') {
      navigator.geolocation.getCurrentPosition(function (position) {
        var center = new OpenLayers.LonLat(
          position.coords.longitude,
          position.coords.latitude
        ).transform(
          new OpenLayers.Projection("EPSG:4326"),
          map.getProjectionObject()
        );
        map.setCenter(center, zoom);
      });
    }
  }
};

})(jQuery);