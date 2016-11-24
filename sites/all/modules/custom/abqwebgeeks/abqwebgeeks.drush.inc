<?php

/**
 * @file
 * Custom Drush integration.
 */

/**
 * Implements hook_drush_command().
 */
function abqwebgeeks_drush_command() {
  return array(
    'golocal' => array(
      'description' => dt('Puts your site in local development mode.'),
    ),
  );
}

/**
 * Put the site in local development mode.
 */
function drush_abqwebgeeks_golocal() {
  // Enable dev friendly modules.
  $modules_to_enable = array(
    'devel',
    'dblog',
    'update',
    'diff',
    'field_ui',
    'views_ui',
    'rules_admin',
    'stage_file_proxy',
  );
  module_enable($modules_to_enable, TRUE);
  foreach ($modules_to_enable as $module) {
    if (module_exists($module)) {
      drush_log(dt('@module enabled', array('@module' => $module)), 'ok');
    }
    else {
      drush_log(dt('@module not enabled!', array('@module' => $module)), 'error');
    }
  }

  // Disable any production modules.
  $disable = array('syslog', 'securepages');
  module_disable($disable);
  drush_log(dt('Modules disabled: @modules', array('@modules' => implode(', ', $disable))), 'ok');

  // Set some dev-friendly settings.
  variable_set('cache', "0");
  variable_set('block_cache', "0");
  variable_set('error_level', "2");
  variable_set('preprocess_js', "0");
  variable_set('preprocess_css', "0");
  variable_set('page_compression', "0");
  drush_log('Page cache, page compression, JS optimization, and CSS optimization disabled.', 'ok');

  // Setup stage_file_proxy settings.
  variable_set('stage_file_proxy_origin', "http://www.abqwebgeeks.org");
  drush_log('Stage file set up.', 'ok');

  // Enable theme_debug.
  variable_set('theme_debug', 1);

  drupal_flush_all_caches();
  drush_log('All caches cleared.', 'ok');

  drush_log('Site ready for development!', 'ok');
}
