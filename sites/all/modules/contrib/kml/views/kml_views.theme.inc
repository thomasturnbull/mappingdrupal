<?php

/**
 * @file
 * Theming functions for KML module views output.
 */

function template_preprocess_views_view_kml(&$vars) {
  $view = $vars['view'];

  $points = $view->style_plugin->map_rows($vars['rows']);

  $style = theme('kml_style', array('points' => $points));

  $rows = '';
  foreach ($points as $point) {
    $rows .= theme('kml_placemark', array('point' => $point, 'points' => $points));
  }

  $vars['rows'] = $rows;
  $vars['style'] = $style;
  $vars['viewtitle'] = $view->get_title();

  // Checks if filename is manually specified in view style options otherwise
  // it sets it as the name of the view.
  if (!empty($view->style_options['filename'])) {
    $filename = $view->style_options['filename'] . '.kml';
  }
  else {
    $filename = $vars['viewtitle'] . '.kml';
  }

  if (empty($vars['view']->live_preview)) {
    drupal_add_http_header('Content-Type', 'application/vnd.google-earth.kml+xml; charset=utf-8');
    drupal_add_http_header('Content-Disposition', "attachment; filename=\"$filename\"");
  }
}

/**
 * Preprocess for theme('kml_placemark').
 */
function template_preprocess_kml_placemark(&$vars) {
  $vars['name'] = filter_xss_admin($vars['point']['name']);
  $vars['description'] = filter_xss_admin($vars['point']['description']);
  $vars['coords'] = check_plain($vars['point']['point']);
  $vars['styleUrl'] = isset($vars['point']['styleUrl']) ? check_plain($vars['point']['styleUrl']) : '';
}

/**
 * Theme function for kml feed icon.
 */
function theme_kml_feed_icon($url, $title, $icon) {
  // TODO: Should this theme kml_feed_icon be declared in hook_theme()?
  if ($image = theme('image', array('path' => $icon, 'width' => t('Download KML Feed'), 'height' => $title))) {
    return '<a href="' . check_url($url)
      . '" class="feed-icon">' . $image . '</a>';
  }
}
