<?php
/**
 * @file
 * user_groups_and_events.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function user_groups_and_events_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass;
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'user_groups';
  $openlayers_maps->title = 'Drupal user groups';
  $openlayers_maps->description = 'A map of Drupal user groups around the world.';
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
          'drupal_groups_openlayers_1' => 'drupal_groups_openlayers_1',
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
      'drupal_groups_openlayers_1' => 'drupal_groups_openlayers_1',
    ),
    'layer_weight' => array(
      'drupal_groups_openlayers_1' => '0',
      'world_earthquakes' => '0',
      'geofield_formatter' => '0',
      'open_gov_projects' => '0',
    ),
    'layer_styles' => array(
      'open_gov_projects' => '0',
      'geofield_formatter' => '0',
      'world_earthquakes' => '0',
      'drupal_groups_openlayers_1' => 'drupal_user_groups',
    ),
    'layer_activated' => array(
      'drupal_groups_openlayers_1' => 'drupal_groups_openlayers_1',
      'open_gov_projects' => 0,
      'geofield_formatter' => 0,
      'world_earthquakes' => 0,
    ),
    'layer_switcher' => array(
      'open_gov_projects' => 0,
      'geofield_formatter' => 0,
      'world_earthquakes' => 0,
      'drupal_groups_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'drupal_user_groups',
      'temporary' => 'default',
    ),
  );
  $export['user_groups'] = $openlayers_maps;

  return $export;
}
