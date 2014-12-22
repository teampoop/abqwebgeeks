<?php
/**
 * @file
 * job_post.features.inc
 */

/**
 * Implements hook_views_api().
 */
function job_post_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function job_post_node_info() {
  $items = array(
    'job_post' => array(
      'name' => t('Job Post'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Don\'t be a jerk.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
