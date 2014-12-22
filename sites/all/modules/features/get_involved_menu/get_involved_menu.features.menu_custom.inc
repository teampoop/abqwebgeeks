<?php
/**
 * @file
 * get_involved_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function get_involved_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-get-involved.
  $menus['menu-get-involved'] = array(
    'menu_name' => 'menu-get-involved',
    'title' => 'Get Involved',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Get Involved');


  return $menus;
}
