<?php
/**
 * @file
 * user_groups_and_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function user_groups_and_events_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_styles") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function user_groups_and_events_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function user_groups_and_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('A Drupal event, such as a camp, meetup, training or social.'),
      'has_title' => '1',
      'title_label' => t('Event name'),
      'help' => '',
    ),
    'user_group' => array(
      'name' => t('User Group'),
      'base' => 'node_content',
      'description' => t('A local Drupal user group'),
      'has_title' => '1',
      'title_label' => t('Group name'),
      'help' => '',
    ),
  );
  return $items;
}
