<?php
/**
 * @file
 * mappingdrupal.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function mappingdrupal_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'earthquake_map';
  $openlayers_maps->title = 'Earthquake Map';
  $openlayers_maps->description = 'A map of the world\'s largest earthquakes from the last 10 years.';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '500px',
    'image_path' => '',
    'css_path' => '',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '0,0',
        'zoom' => '2',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'world_earthquakes' => 'world_earthquakes',
        ),
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(),
    ),
    'default_layer' => 'osm_mapnik',
    'layers' => array(
      'osm_mapnik' => 'osm_mapnik',
      'world_earthquakes' => 'world_earthquakes',
    ),
    'layer_weight' => array(
      'world_earthquakes' => '0',
      'geofield_formatter' => '0',
      'open_gov_projects' => '0',
    ),
    'layer_styles' => array(
      'open_gov_projects' => '0',
      'geofield_formatter' => '0',
      'world_earthquakes' => 'earthquake',
    ),
    'layer_activated' => array(
      'world_earthquakes' => 'world_earthquakes',
      'open_gov_projects' => 0,
      'geofield_formatter' => 0,
    ),
    'layer_switcher' => array(
      'world_earthquakes' => 'world_earthquakes',
      'open_gov_projects' => 0,
      'geofield_formatter' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'earthquake',
      'select' => 'earthquake',
      'temporary' => 'earthquake',
    ),
  );
  $export['earthquake_map'] = $openlayers_maps;

  return $export;
}