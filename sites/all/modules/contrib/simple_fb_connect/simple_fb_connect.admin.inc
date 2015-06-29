<?php

/**
 * @file
 * Administration page callbacks for the simple fb connect module.
 */
function simple_fb_connect_api_keys_settings($form, &$form_state) {
  $form['simple_fb_connect_appid'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Application ID'),
    '#default_value' => variable_get('simple_fb_connect_appid', NULL),
    '#description' => t('Also called the <em>OAuth client_id</em> value on Facebook App settings pages. <a href="https://www.facebook.com/developers/createapp.php">Facebook Apps must first be created</a> before they can be added here.'),
  );

  $form['simple_fb_connect_skey'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Application Secret'),
    '#default_value' => variable_get('simple_fb_connect_skey', NULL),
    '#description' => t('Also called the <em>OAuth client_secret</em> value on Facebook App settings pages.'),
  );


  $form['simple_fb_connect_connect_url'] = array(
    '#type' => 'textfield',
    '#attributes' => array('readonly' => 'readonly'),
    '#title' => t('Connect url'),
    '#description' => t('Copy this value into Facebook Applications on Connect settings tab'),
    '#default_value' => $GLOBALS['base_url'],
  );

  $form['simple_fb_connect_login_only'] = array(
    '#type' => 'checkbox',
    '#title' => t('Login Only (No Registration)'),
    '#description' => t('Allow only existing users to login with FB. New users can not signup using FB Connect.'),
    '#default_value' => variable_get('simple_fb_connect_login_only', 0),
  );
 
  $form['simple_fb_connect_post_login_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Post Login url'),
    '#description' => t('Drupal URL to which the user should be redirected to after successful login.'),
    '#default_value' => variable_get('simple_fb_connect_post_login_url', ''),
  );

  return system_settings_form($form);
}
