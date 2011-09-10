<?php
/**
 * @file
 * mappingdrupal.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function mappingdrupal_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_source';
  $strongarm->value = 'http://openlayers.org/api/2.10/OpenLayers.js';
  $export['openlayers_source'] = $strongarm;

  return $export;
}
