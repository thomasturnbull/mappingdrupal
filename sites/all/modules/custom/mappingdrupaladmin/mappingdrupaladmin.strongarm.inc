<?php
/**
 * @file
 * mappingdrupaladmin.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function mappingdrupaladmin_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clean_url';
  $strongarm->value = 1;
  $export['clean_url'] = $strongarm;

  return $export;
}
