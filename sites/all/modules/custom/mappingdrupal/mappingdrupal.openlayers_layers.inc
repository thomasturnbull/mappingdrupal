<?php
/**
 * @file
 * mappingdrupal.openlayers_layers.inc
 */

/**
 * Implementation of hook_openlayers_layers().
 */
function mappingdrupal_openlayers_layers() {
  $export = array();

  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'world_earthquakes';
  $openlayers_layers->title = 'Largest Earthquakes';
  $openlayers_layers->description = 'Largest Earthquakes in the World Since 1900 - USGS';
  $openlayers_layers->data = array(
    'url' => 'sites/all/modules/custom/mappingdrupal/LargestWorldEarthquakes.kml',
    'formatOptions' => array(
      'extractStyles' => 0,
      'extractAttributes' => 0,
    ),
    'layer_type' => 'openlayers_layer_type_kml',
  );
  $export['world_earthquakes'] = $openlayers_layers;

  return $export;
}
