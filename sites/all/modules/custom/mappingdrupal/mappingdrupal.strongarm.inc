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
  $strongarm->name = 'node_options_user_group';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_user_group'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_user_group';
  $strongarm->value = '1';
  $export['node_preview_user_group'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_user_group';
  $strongarm->value = 1;
  $export['node_submitted_user_group'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'openlayers_source';
  $strongarm->value = 'sites/all/libraries/OpenLayers-2.10/OpenLayers.js';
  $export['openlayers_source'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_user_group';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_user_group'] = $strongarm;

  return $export;
}
