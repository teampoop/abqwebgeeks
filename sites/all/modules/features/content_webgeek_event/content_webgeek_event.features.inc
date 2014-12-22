<?php
/**
 * @file
 * content_webgeek_event.features.inc
 */

/**
 * Implements hook_node_info().
 */
function content_webgeek_event_node_info() {
  $items = array(
    'webgeek_event' => array(
      'name' => t('Webgeek Event'),
      'base' => 'node_content',
      'description' => t('Here are our events. They are better than other events.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
