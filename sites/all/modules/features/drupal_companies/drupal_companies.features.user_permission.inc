<?php
/**
 * @file
 * drupal_companies.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drupal_companies_user_default_permissions() {
  $permissions = array();

  // Exported permission: create drupal_company content
  $permissions['create drupal_company content'] = array(
    'name' => 'create drupal_company content',
    'roles' => array(),
  );

  // Exported permission: create gmap macro
  $permissions['create gmap macro'] = array(
    'name' => 'create gmap macro',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'gmap_macro_builder',
  );

  // Exported permission: delete any drupal_company content
  $permissions['delete any drupal_company content'] = array(
    'name' => 'delete any drupal_company content',
    'roles' => array(),
  );

  // Exported permission: delete own drupal_company content
  $permissions['delete own drupal_company content'] = array(
    'name' => 'delete own drupal_company content',
    'roles' => array(),
  );

  // Exported permission: edit any drupal_company content
  $permissions['edit any drupal_company content'] = array(
    'name' => 'edit any drupal_company content',
    'roles' => array(),
  );

  // Exported permission: edit own drupal_company content
  $permissions['edit own drupal_company content'] = array(
    'name' => 'edit own drupal_company content',
    'roles' => array(),
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

  return $permissions;
}
