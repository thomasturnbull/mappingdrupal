/**
 * @file
 * Main Javascript file for Mapping with Drupal GMap Extensions module.
 *
 * Provides geolocation functionality for a Gmap.
 */
 
// Namespace $ for jQuery.  This ensures that $ will
// actually equal the jQuery function.
(function($) {

/**
 * Wrap handlers in a Drupal behavior so that
 * we can be sure that everything is available.
 */
Drupal.behaviors.mappingdrupal_gmap_extensions = {
  'attach': function(context, settings) {
    // The following ensures that the behavior is only performed
    // once.  Since we are adding a handler for all Gmap maps, 
    // we are not concerned with context.
    $('body').once(function() {
      // Add a handler to the map
      Drupal.gmap.addHandler('gmap', function(elem) {
        var gmap = this;
        
        // gmap (this) is the main gmap module with the following
        // main properties:
        // - map: The Google Maps API object.
        // - vars: The configuration passed from Drupal.
        //
        // elem is the DOM object that holds the Google Map.
        
        // The ready event is fired when things are ready with
        // the map.
        gmap.bind('ready', function() {
          // We normally should check for the behavior to geolocate,
          // but it does not seem to be available.
          Drupal.behaviors.mappingdrupal_gmap_extensions.geolocate(gmap.map);
          
          // Again, we should be checking for the proper behavior
          // but for some reason it is not available.
          //
          // We utilize jQuery to turn out block into a link
          // to update the map with user's location.
          $('.mappingdrupal-gmap-geolocate-action')
            .show()
            .html(Drupal.t('Find me on the map.'))
            .click(function(e) {
              Drupal.behaviors.mappingdrupal_gmap_extensions.geolocate(gmap.map);
              e.preventDefault();
            });
        });
      });
    });
  },
  
  // General function to geolocate user.
  'geolocate': function(map) {
    // Firest ensure that that the HTML5 geolocation controls
    // are available.  We might use some more helpful
    // libraries for this, like Modernizr
    if (typeof navigator != 'undefined' && 
      typeof navigator.geolocation != 'undefined') {
      navigator.geolocation.getCurrentPosition(function (position) {
        lat = position.coords.latitude;
        lng = position.coords.longitude;
        map.setCenter(new google.maps.LatLng(lat, lng));
        map.setZoom(11);
      });
    }
  }
};

})(jQuery);

