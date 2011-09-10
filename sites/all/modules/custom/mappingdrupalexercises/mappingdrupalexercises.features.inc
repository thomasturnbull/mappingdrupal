<?php
/**
 * @file
 * mappingdrupalexercises.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mappingdrupalexercises_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_node_info().
 */
function mappingdrupalexercises_node_info() {
  $items = array(
    'exercise' => array(
      'name' => t('Exercise'),
      'base' => 'node_content',
      'description' => t('Pages that description sample exercises on the site.  These can be used to link to the different pages of an exercise or sample.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
