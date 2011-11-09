<?php
/**
 * @file
 * drupal_companies.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drupal_companies_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function drupal_companies_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function drupal_companies_node_info() {
  $items = array(
    'drupal_company' => array(
      'name' => t('Drupal Company'),
      'base' => 'node_content',
      'description' => t('A Drupal development company'),
      'has_title' => '1',
      'title_label' => t('Company name'),
      'help' => '',
    ),
  );
  return $items;
}
