<?php
/**
 * @file
 * mappingdrupalexercises.strongarm.inc
 */

/**
 * Implementation of hook_strongarm().
 */
function mappingdrupalexercises_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_exercise';
  $strongarm->value = 0;
  $export['comment_anonymous_exercise'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_exercise';
  $strongarm->value = 1;
  $export['comment_default_mode_exercise'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_exercise';
  $strongarm->value = '50';
  $export['comment_default_per_page_exercise'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_exercise';
  $strongarm->value = '2';
  $export['comment_exercise'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_exercise';
  $strongarm->value = 1;
  $export['comment_form_location_exercise'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_exercise';
  $strongarm->value = '1';
  $export['comment_preview_exercise'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_exercise';
  $strongarm->value = 1;
  $export['comment_subject_field_exercise'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_exercise';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_exercise'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_exercise_pattern';
  $strongarm->value = 'exercise/[node:title]';
  $export['pathauto_node_exercise_pattern'] = $strongarm;

  return $export;
}
