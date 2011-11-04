<?php
/**
 * @file
 * mappingdrupal.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mappingdrupal_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'drupal_groups';
  $view->description = 'Drupal groups data layer for a map';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Drupal groups';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Drupal groups data layer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_group_location',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => 'body',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Group location */
  $handler->display->display_options['fields']['field_group_location']['id'] = 'field_group_location';
  $handler->display->display_options['fields']['field_group_location']['table'] = 'field_data_field_group_location';
  $handler->display->display_options['fields']['field_group_location']['field'] = 'field_group_location';
  $handler->display->display_options['fields']['field_group_location']['label'] = '';
  $handler->display->display_options['fields']['field_group_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_group_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_group_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_group_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_group_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_group_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_group_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_group_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_group_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_group_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_group_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_group_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_group_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_group_location']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_group_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_group_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_group_location']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_group_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_group_location']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_group_location']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'user_group' => 'user_group',
  );

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $export['drupal_groups'] = $view;

  return $export;
}
