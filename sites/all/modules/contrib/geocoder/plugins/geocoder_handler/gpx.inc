<?php // $Id: gpx.inc,v 1.1 2009/03/02 18:14:07 vauxia Exp $


/**
 * @file
 *
 * Parsing utilities for GPX track files.  Originally written to cover a more
 * comprehensive usage than what Geocode is doing, but handy nonetheless.
 *
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("GPX"),
  'description' => t('Get the geomtry of a GPX string or file'),
  'callback' => 'geocoder_gpx',
  'field_types' => array('text','text_long','file','computed'),
  'field_callback' => 'geocoder_gpx_field',
);

/**
 * Process GPX
 */
function geocoder_gpx($gpx_string) {
  geocoder_load_geophp();
  return geoPHP::load($gpx_string,'gpx');
}

function geocoder_gpx_field($field, $field_item) {
  if ($field['type'] == 'text' || $field['type'] == 'text_long' || $field['type'] == 'computed') {
  	return geocoder_gpx($field_item['value']);
  }
  if ($field['type'] == 'file') {
  	$file = file_load($field_item['fid']);
  	$gpx = file_get_contents($file->uri);
  	return geocoder_gpx($gpx);
  }
}

