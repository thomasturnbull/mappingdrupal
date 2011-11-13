<?php
/**
 * @file
 * Implementation of OpenLayers behavior for HTML5 geolocation.
 */

/**
 * Geolocation behavior.
 */
class mappingdrupal_ol_extensions_geolocate extends openlayers_behavior {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'on_load' => FALSE,
      'button' => TRUE,
      'zoom' => 11,
    );
  }

  /**
   * Provide form for configurations per map.
   */
  function options_form($defaults) {
    return array(
      'on_load' => array(
        '#title' => t('Geolocate on load'),
        '#type' => 'checkbox',
        '#description' => t('When checked, the map will geolocate the user 
          and zoom in when the map first loads.'),
        '#default_value' => isset($defaults['on_load']) ?  
          $defaults['on_load'] : FALSE
      ),
      'button' => array(
        '#title' => t('Geolocate button'),
        '#type' => 'checkbox',
        '#description' => t('When checked, provides a button on the map that 
          will geolocate the user.'),
        '#default_value' => isset($defaults['button']) ? 
          $defaults['button'] : TRUE
      ),
      'zoom' => array(
        '#title' => t('Zoom level'),
        '#type' => 'textfield',
        '#description' => t('Determine the zoom level when geolocating.  Higher 
          is more zoomed in.'),
        '#default_value' => isset($defaults['zoom']) ? 
          $defaults['zoom'] : 11
      ),
    );
  }

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_css(drupal_get_path('module', 'mappingdrupal_ol_extensions') .
      '/behaviors/mappingdrupal_ol_extensions_geolocate.css');
    drupal_add_js(drupal_get_path('module', 'mappingdrupal_ol_extensions') .
      '/behaviors/mappingdrupal_ol_extensions_geolocate.js');
    return $this->options;
  }
}

