<?php
/**
 * @file
 * local_event.features.inc
 */

/**
 * Implements hook_node_info().
 */
function local_event_node_info() {
  $items = array(
    'local_event' => array(
      'name' => t('Local Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
