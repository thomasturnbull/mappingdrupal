<?php
/**
 * @file
 * user_groups_and_events.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function user_groups_and_events_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer openlayers
  $permissions['administer openlayers'] = array(
    'name' => 'administer openlayers',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openlayers_ui',
  );

  // Exported permission: create event content
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(),
  );

  // Exported permission: create user_group content
  $permissions['create user_group content'] = array(
    'name' => 'create user_group content',
    'roles' => array(),
  );

  // Exported permission: delete any event content
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(),
  );

  // Exported permission: delete any user_group content
  $permissions['delete any user_group content'] = array(
    'name' => 'delete any user_group content',
    'roles' => array(),
  );

  // Exported permission: delete own event content
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(),
  );

  // Exported permission: delete own user_group content
  $permissions['delete own user_group content'] = array(
    'name' => 'delete own user_group content',
    'roles' => array(),
  );

  // Exported permission: edit any event content
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(),
  );

  // Exported permission: edit any user_group content
  $permissions['edit any user_group content'] = array(
    'name' => 'edit any user_group content',
    'roles' => array(),
  );

  // Exported permission: edit own event content
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(),
  );

  // Exported permission: edit own user_group content
  $permissions['edit own user_group content'] = array(
    'name' => 'edit own user_group content',
    'roles' => array(),
  );

  return $permissions;
}
