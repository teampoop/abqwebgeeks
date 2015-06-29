<?php

/**
 * @file
 * Hooks provided by the Simple FB Connect module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Allow modules to play with the information received from the FB profile like
 * mapping it to fields in user profile.
 *
 * @param $fields
 *   The fields array to be stored with user profile in user_save.
 *   Modify these values with values from $fb_user_profile to populate
 *   User Profile with values from FB while creating new user.
 *
 * @param $fb_user_profile
 *   The user array received from Facebook. Contains information about your user
 *   received from facebook
 *
 */
function hook_simple_fb_connect_register_alter(&$fields, $fb_user_profile) {
  //Do stuff with $fields
}


/**
 * Allows to change the permissions requested by the module
 *
 * @param $scope
 *   The scope array listing various permissions requested by the module.
 *
 * @return
 *   The updated scope array
 */
function hook_simple_fb_scope_info($scope) {
  //Modify the scope array
  //by default the module requests only "email"
  //Simple_FB_Publish module adds "publish_stream" to the scope
  //You can add more here
  return $scope;
}