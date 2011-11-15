<?php

/**
 * @file
 * Extending the view_plugin_style class to provide a kml view style.
 */
class views_plugin_style_kml extends views_plugin_style {

  /**
   * Initialize plugin.
   *
   * Set feed image for shared rendering later.
   */
  function init(&$view, &$display, $options = NULL) {
    parent::init($view, $display, $options = NULL);
    $this->feed_image = drupal_get_path('module', 'kml') . '/images/kml.png';
  }

  /**
   * Attach this view to another display as a feed.
   *
   * Provide basic functionality for all export style views like attaching a
   * feed image link.
   */
  function attach_to($display_id, $path, $title) {
    $url_options = array('html' => TRUE);

    // Include exposed filters
    $query = $this->view->get_exposed_input();
    if ($query) {
      $url_options['query'] = $query;
    }

    $image = theme('image', array('path' => $this->feed_image));
    $this->view->feed_icon .= l($image, $this->view->get_url(NULL, $path), $url_options);
  }

  function option_definition() {
    $options = parent::option_definition();

    $field_options = array(
      'name' => t('Name'),
      'description' => t('Description'),
      'longitude' => t('Longitude'),
      'latitude' => t('Latitude'),
    );

    foreach ($field_options as $k => $v) {
      $fields[$k] = array('default' => '');
    }

    $options['fields'] = array(
      'contains' => $fields,
    );
    $options['filename'] = array(
      'default' => isset($this->filename) ? $this->filename : '',
      'translatable' => FALSE,
    );

    return $options;
  }


  /**
   * Provide a form for setting options.
   *
   * @param array $form
   * @param array $form_state
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $options = parent::option_definition();

    $handlers = $this->display->handler->get_handlers('field');
    if (empty($handlers)) {
      $form['error_markup'] = array(
        '#value' => t('You need at least one field before you can
        configure your field settings'),
        '#prefix' => '<div class="error form-item description">',
        '#suffix' => '</div>',
      );
    }
    else {
      $field_names[$field] = array('' => '--');
      foreach ($handlers as $field => $handler) {
        if ($label = $handler->label()) {
          $field_names[$field] = $label;
        }
        else {
          $field_names[$field] = $handler->ui_name();
        }
      }
      $field_options = array(
        'name' => t('Name'),
        'description' => t('Description'),
        'longitude' => t('Longitude'),
        'latitude' => t('Latitude'),
      );
      $form['filename'] = array(
        '#type' => 'textfield',
        '#title' => t('Filename'),
        '#default_value' => $this->options['filename'],
        '#description' => t('The filename that will be suggested to the browser
        for downloading purposes. Leave empty to use the view title. ".kml"
        will be automatically appended.'),
      );
      $form['fields'] = array(
        '#type' => 'fieldset',
        '#title' => 'Field usage',
        '#description' => t('Select the fields that contain the latitude,
        longitude and title of each point.
        Remaining fields will be available in the
        "content" region of the point.'),
        '#weight' => -10,
      );
      foreach ($field_options as $k => $v) {
        $form['fields'][$k] = array(
          '#type' => 'select',
          '#title' => $v,
          '#options' => $field_names,
          '#default_value' => $this->options['fields'][$k],
          '#required' => ($k == 'class' ? FALSE : TRUE),
        );
      }
    }
  }

  function map_rows($rows) {
    // Fields must be rendered in order as of Views 2.3,
    // so we will pre-render everything.
    $renders = array();
    $keys = array_keys($this->view->field);

    $renders = $this->render_fields($rows);

    $points = array();
    foreach ($renders as $id => $row) {
      $point = array();
      foreach ($this->view->field as $key => $field) {
        if ($key == $this->options['fields']['name']) {
          $point['name'] = $row[$key];
        }
        elseif ($key == $this->options['fields']['description']) {
          $point['description'] = $row[$key];
        }
        elseif ($key == $this->options['fields']['longitude']) {
          $point['lon'] = $row[$key];
        }
        elseif ($key == $this->options['fields']['latitude']) {
          $point['lat'] = $row[$key];
        }
      }

      $point['point'] = $point['lon'] . ',' . $point['lat'] . ',0';
      unset($point['lat']);
      unset($point['lon']);

      if (isset($this->options['linestring']) && $this->options['linestring']['enable']) {
        $points[$point['group']][] = $point;
      }
      else {
        $points[] = $point;
      }
    }
    return $points;
  }
}
