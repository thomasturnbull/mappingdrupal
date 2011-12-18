<?php

/**
 * @file
 * Main template file for Mapping Drupal Bootstrap theme.
 */

/**
 * Include other files.
 */
require_once dirname(__FILE__) . '/includes/template.forms.php';
require_once dirname(__FILE__) . '/includes/template.fields.php';

/**
 * Implements hook_css_alter().
 */
function mappingdrupal_bootstrap_css_alter(&$css) {
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
  unset($css[drupal_get_path('module', 'system') . '/system.theme.css']);
  unset($css[drupal_get_path('module', 'system') . '/system.messages.css']);
}

/**
 * Implements hook_preprocess_html().
 */
function mappingdrupal_bootstrap_preprocess_html(&$variables) {
  $fluid = mappingdrupal_bootstrap_determine_fluid();
  
  if ($fluid) {
    $variables['classes_array'][] = 'fluid';
  }
}

/**
 * Implements hook_preprocess_page().
 */
function mappingdrupal_bootstrap_preprocess_page(&$variables) {
  global $language;
  $variables['fluid'] = mappingdrupal_bootstrap_determine_fluid();
  
  // Hard code logo
  //$variables['logo'] = base_path() . drupal_get_path('theme', 'mappingdrupal_bootstrap') . '/images/logo/logo_white_tree-35.png';
  
  // Node operations
  $variables['sub_title'] = null;
  if (isset($variables['node'])) {
    // Get subtitle for page.
    $sub_titles = field_get_items('node', $variables['node'], 'field_subtitle', $variables['node']->language);
    if (!empty($sub_titles)) {
      $variables['sub_title'] = $sub_titles[0]['safe_value'];
    }
  }
  
  // Handle a one-page site if front page
  if (drupal_is_front_page()) {
    mappingdrupal_bootstrap_single_page($variables);
  }
}

/**
 * Implements hook_preprocess_comment_wrapper().
 */
function mappingdrupal_bootstrap_preprocess_comment_wrapper(&$variables) {
  $variables['classes_array'][] = 'well';
}

/**
 * Implements hook_form_N_alter().
 */
function mappingdrupal_bootstrap_form_comment_form_alter(&$form) {
  $form['#attributes']['class'][] = 'well';
}

/**
 * Overrides theme_status_messages().
 */
function mappingdrupal_bootstrap_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'), 
    'error' => t('Error message'), 
    'warning' => t('Warning message'),
  );
  
  $bootstrap_classes = array(
    'status' => 'success',  // info
    'error' => 'error', 
    'warning' => 'warning',
    'success' => 'success',
  );
  
  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= '<div class="messages ' . $bootstrap_classes[$type] . ' alert-message">';
    $output .= '<a class="close" href="#">x</a>';
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>\n";
    }
    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }
    $output .= "</div>\n";
  }
  return $output;
}

/**
 * Overrides theme_links().
 *
 * Specific for nodes.
 */
function mappingdrupal_bootstrap_links__node($variables) {
  // If inline links, then we should add some classes.
  if (in_array('inline', $variables['attributes']['class'])) {
    foreach ($variables['links'] as $k => $link) {
      $variables['links'][$k]['attributes']['class'][] = 'btn';
    }
  }
  
  // Clearfix
  $variables['attributes']['class'][] = 'clearfix';

  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  $output = '';

  if (count($links) > 0) {
    $output = '';

    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading. 
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);

      // Make each one a button
      $link['attributes']['class'][] = 'btn info';

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
           && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

/**
 * Overrides theme_links().
 *
 * Specific for comments.
 */
function mappingdrupal_bootstrap_links__comment($variables) {
  // If inline links, then we should add some classes.
  if (in_array('inline', $variables['attributes']['class'])) {
    foreach ($variables['links'] as $k => $link) {
      $variables['links'][$k]['attributes']['class'][] = 'btn small';
    }
  }
  
  return mappingdrupal_bootstrap_links__node($variables);
}
/**
 * Overrides theme_pager().
 */
function mappingdrupal_bootstrap_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('pager-first', 'prev'), 
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous', 'prev'), 
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'), 
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'), 
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current', 'disabled'), 
            'data' => '<a href="#">' . $i . '</a>',
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'), 
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'), 
          'data' => '…',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'), 
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last', 'next'), 
        'data' => $li_last,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . 
      '<div class="pagination">' .
      theme('item_list', array(
        'items' => $items, 
        'attributes' => array('class' => array('pager')),
      )) .
      '</div>';
  }
}

/**
 * Determine if page should be fluid.
 */
function mappingdrupal_bootstrap_determine_fluid() {
  $is_fluid = false;
  
  $path = current_path();
  $front = drupal_is_front_page();
  
  if ($front) {
    //$is_fluid = true;
  }
  
  return $is_fluid;
}

/**
 * Handle changing page into a one-page site by
 * using the main-menu links to render the pages
 * and make them into anchor links.
 */
function mappingdrupal_bootstrap_single_page(&$variables) {
  $links = menu_load_links('main-menu');
  $count = 0;
  $title = drupal_get_title();
  
  // Go through links and add render arrays to content.
  foreach ($links as $id => $link) {
    $count++;
    
    // Ensure that its not the front page or the current
    // page.
    if ($link['link_path'] != '<front>' && current_path() != $link['link_path']) {
      $alias = drupal_get_path_alias($link['link_path']);
      $item_array = menu_execute_active_handler($link['link_path'], FALSE);
      
      // Add a prefix to items so that they are anchorable
      $item_array['#prefix'] = (isset($item_array['#prefix'])) ? $item_array['#prefix'] : '';
      $item_array['#prefix'] .= '<a name="' . $alias . '" id="' . $alias . '"></a>';
      
      // Add a suffix to items so that they go back to top
      $item_array['#suffix'] = (isset($item_array['#suffix'])) ? $item_array['#suffix'] : '';
      $item_array['#suffix'] .= '<a href="#page-top" class="back-to-top anchor-scroll">' . 
        t('Back to top') . '</a>';

      // Add render arrays to page content.
      $variables['page']['content'][$alias . '-' . $count] = $item_array;
    }
  }
  
  // Go through and update menu links
  $main = $variables['main_menu'];
  foreach ($main as $id => $main_item) {
    $alias = drupal_get_path_alias($main_item['href']);
    if ($main_item['href'] == '<front>') {
      $alias = 'page-top';
    }
    
    // Do some magic to get things to work correctly;
    $variables['main_menu'][$id]['href'] = '';
    $variables['main_menu'][$id]['fragment'] = $alias;
    $variables['main_menu'][$id]['attributes']['class'][] = 'anchor-scroll';
    $variables['main_menu'][$id]['external'] = TRUE;
  }
  
  drupal_set_title($title);
}