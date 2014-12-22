<?php
/**
 * @file
 * job_post.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function job_post_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'job_posts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Job Posts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Job Posts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'masonry_views';
  $handler->display->display_options['style_options']['masonry_column_width'] = '30';
  $handler->display->display_options['style_options']['masonry_column_width_units'] = '%';
  $handler->display->display_options['style_options']['masonry_gutter_width'] = '5';
  $handler->display->display_options['style_options']['masonry_resizable'] = TRUE;
  $handler->display->display_options['style_options']['masonry_animated'] = TRUE;
  $handler->display->display_options['style_options']['masonry_fit_width'] = TRUE;
  $handler->display->display_options['style_options']['masonry_rtl'] = FALSE;
  $handler->display->display_options['style_options']['masonry_images_first'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Description';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '400',
  );
  /* Field: Content: Who */
  $handler->display->display_options['fields']['field_job_post_company']['id'] = 'field_job_post_company';
  $handler->display->display_options['fields']['field_job_post_company']['table'] = 'field_data_field_job_post_company';
  $handler->display->display_options['fields']['field_job_post_company']['field'] = 'field_job_post_company';
  $handler->display->display_options['fields']['field_job_post_company']['type'] = 'text_plain';
  /* Field: Content: How Much */
  $handler->display->display_options['fields']['field_job_post_rate']['id'] = 'field_job_post_rate';
  $handler->display->display_options['fields']['field_job_post_rate']['table'] = 'field_data_field_job_post_rate';
  $handler->display->display_options['fields']['field_job_post_rate']['field'] = 'field_job_post_rate';
  /* Field: Content: What */
  $handler->display->display_options['fields']['field_job_post_type']['id'] = 'field_job_post_type';
  $handler->display->display_options['fields']['field_job_post_type']['table'] = 'field_data_field_job_post_type';
  $handler->display->display_options['fields']['field_job_post_type']['field'] = 'field_job_post_type';
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
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job_post' => 'job_post',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Posted (field_job_post_starts) */
  $handler->display->display_options['filters']['field_job_post_starts_value']['id'] = 'field_job_post_starts_value';
  $handler->display->display_options['filters']['field_job_post_starts_value']['table'] = 'field_data_field_job_post_starts';
  $handler->display->display_options['filters']['field_job_post_starts_value']['field'] = 'field_job_post_starts_value';
  $handler->display->display_options['filters']['field_job_post_starts_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_job_post_starts_value']['group'] = 1;
  $handler->display->display_options['filters']['field_job_post_starts_value']['default_date'] = 'now';
  /* Filter criterion: Content: Post Remove (field_job_post_remove) */
  $handler->display->display_options['filters']['field_job_post_remove_value']['id'] = 'field_job_post_remove_value';
  $handler->display->display_options['filters']['field_job_post_remove_value']['table'] = 'field_data_field_job_post_remove';
  $handler->display->display_options['filters']['field_job_post_remove_value']['field'] = 'field_job_post_remove_value';
  $handler->display->display_options['filters']['field_job_post_remove_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_job_post_remove_value']['group'] = 1;
  $handler->display->display_options['filters']['field_job_post_remove_value']['default_date'] = 'now';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'job-posts';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Jobs';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['job_posts'] = array(
    t('Master'),
    t('Job Posts'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Description'),
    t('Who'),
    t('How Much'),
    t('What'),
    t('Page'),
  );
  $export['job_posts'] = $view;

  return $export;
}
