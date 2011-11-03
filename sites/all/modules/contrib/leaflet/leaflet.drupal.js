Drupal.behaviors.leaflet = {
  attach: function (context, settings) {
		// declare at this level to these vars are accessable to functions
    var bounds, map;

    jQuery(settings.leaflet).each(function() {
      // load a settings object with all of our map settings
      var settings = {};
      for (var setting in this.map.settings) {
        settings[setting] = this.map.settings[setting];
      }
      
      // instantiate our new map
      map = new L.Map(this.mapId, settings);

      // add map layers
      var layers = {};
      var i = 0;
      for (var key in this.map.layers) {
				var layer = this.map.layers[key];
        var map_layer = new L.TileLayer(layer.urlTemplate);
        if (layer.options) {
          for (var option in layer.options) {
             map_layer.options[option] = layer.options[option];
           }          
        }
        layers[layer] = map_layer;
      
        // add the first layer to the map
        if (i === 0) {
          map.addLayer(map_layer);          
        }
        i++;        
      }
      
      // add layer switcher
      if (this.map.settings.layerControl) {
        map.addControl(new L.Control.Layers(layers));
      }
      
      // add markers
			bounds = []; // bounds is used to fit the map to all points
      for (var i=0; i < this.features.length; i++) {
        var feature = this.features[i];
				var lFeature;
				switch(feature.type) {
					case 'point':
						lFeature = leaflet_create_point(feature);
						break;
					case 'linestring':
						lFeature = leaflet_create_linestring(feature);
						break;
					case 'polygon':
						lFeature = leaflet_create_polygon(feature);
						break;
          case 'multipolygon':
            lFeature = leaflet_create_multipolygon(feature);
            break;
				}

	      map.addLayer(lFeature);
	      if (feature.popup) {
	        lFeature.bindPopup(feature.popup);
	      }				
      }
console.log(bounds);
      // either center the map or set to bounds
      if (this.map.center) {
        map.setView(new L.LatLng(this.map.center.lat, this.map.center.lon), this.map.settings.zoom);
      }
      else {
        map.fitBounds(new L.LatLngBounds(bounds));        
      }

      // add attribution
      if (this.map.settings.attributionControl && this.map.attribution) {
        map.attributionControl.setPrefix(this.map.attribution.prefix);
        map.attributionControl.addAttribution(this.map.attribution.text);
      }
    });

		function leaflet_create_point(marker) {
      var latLng = new L.LatLng(marker.lat, marker.lon);
      bounds.push(latLng);
			var lMarker;
      if (marker.icon) {
        var icon = new L.Icon(marker.icon.iconUrl);
        icon.iconSize = new L.Point(marker.icon.iconSize.x, marker.icon.iconSize.y);
        icon.iconAnchor = new L.Point(marker.icon.iconAnchor.x, marker.icon.iconAnchor.y);
        icon.popupAnchor = new L.Point(marker.icon.popupAnchor.x, marker.icon.popupAnchor.y);
        icon.shadowUrl = marker.icon.shadowUrl;
        lMarker = new L.Marker(latLng, {icon: icon});
      }
      else {
        lMarker = new L.Marker(latLng);
      }

      return lMarker;		
		}
		
		function leaflet_create_linestring(polyline) {
			var latlngs = [];
			for (var i=0; i < polyline.points.length; i++) {
				var latlng = new L.LatLng(polyline.points[i].lat, polyline.points[i].lon);
        latlngs.push(latlng);
        bounds.push(latlng);
			}
			return new L.Polyline(latlngs);			
		}
		
		function leaflet_create_polygon(polygon) {
			var latlngs = [];
			for (var i=0; i < polygon.points.length; i++) {
				var latlng = new L.LatLng(polygon.points[i].lat, polygon.points[i].lon);
        latlngs.push(latlng);
        bounds.push(latlng);
			}
			return new L.Polygon(latlngs);
		}

    function leaflet_create_multipolygon(multipolygon) {
      var polygons = [];
      for (var x=0; x < multipolygon.polygons.length; x++) {
        var latlngs = [];
        var polygon = multipolygon.polygons[x];
        for (var i=0; i < polygon.points.length; i++) {
          var latlng = new L.LatLng(polygon.points[i].lat, polygon.points[i].lon);
          latlngs.push(latlng);
          bounds.push(latlng);
        }
        polygons.push(latlngs);
      }
      return new L.MultiPolygon(polygons);
    }
  }
};
