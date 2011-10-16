<?php
/**
 * @file
 * mappingdrupal.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mappingdrupal_user_default_permissions() {
  $permissions = array();

  // Exported permission: create gmap macro
  $permissions['create gmap macro'] = array(
    'name' => 'create gmap macro',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'gmap_macro_builder',
  );

  // Exported permission: submit latitude/longitude
  $permissions['submit latitude/longitude'] = array(
    'name' => 'submit latitude/longitude',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'location',
  );

  // Exported permission: view location directory
  $permissions['view location directory'] = array(
    'name' => 'view location directory',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: view node location table
  $permissions['view node location table'] = array(
    'name' => 'view node location table',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: view node map
  $permissions['view node map'] = array(
    'name' => 'view node map',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'gmap_location',
  );

  // Exported permission: view user location details
  $permissions['view user location details'] = array(
    'name' => 'view user location details',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'gmap_location',
  );

  // Exported permission: view user location table
  $permissions['view user location table'] = array(
    'name' => 'view user location table',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: view user map
  $permissions['view user map'] = array(
    'name' => 'view user map',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'gmap_location',
  );

  return $permissions;
}
