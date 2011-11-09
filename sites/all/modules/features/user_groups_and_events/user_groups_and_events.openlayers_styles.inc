<?php
/**
 * @file
 * user_groups_and_events.openlayers_styles.inc
 */

/**
 * Implements hook_openlayers_styles().
 */
function user_groups_and_events_openlayers_styles() {
  $export = array();

  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'drupal_user_groups';
  $openlayers_styles->title = 'Drupal user groups';
  $openlayers_styles->description = '';
  $openlayers_styles->data = array(
    'pointRadius' => 5,
    'fillColor' => '#53b0eb',
    'strokeColor' => '#0678be',
    'strokeWidth' => 1,
    'fillOpacity' => 0.8,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicOpacity' => 1,
    'labelAlign' => 'cm',
  );
  $export['drupal_user_groups'] = $openlayers_styles;

  return $export;
}
