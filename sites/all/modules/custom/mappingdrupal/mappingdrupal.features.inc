<?php
/**
 * @file
 * mappingdrupal.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mappingdrupal_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_layers") {
    return array("version" => "1");
  }
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
 * Implements hook_node_info().
 */
function mappingdrupal_node_info() {
  $items = array(
    'drupal_company' => array(
      'name' => t('Drupal Company'),
      'base' => 'node_content',
      'description' => t('A Drupal development company'),
      'has_title' => '1',
      'title_label' => t('Company name'),
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
