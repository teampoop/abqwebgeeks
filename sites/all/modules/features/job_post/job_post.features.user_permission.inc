<?php
/**
 * @file
 * job_post.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function job_post_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create job_post content'.
  $permissions['create job_post content'] = array(
    'name' => 'create job_post content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any job_post content'.
  $permissions['delete any job_post content'] = array(
    'name' => 'delete any job_post content',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own job_post content'.
  $permissions['delete own job_post content'] = array(
    'name' => 'delete own job_post content',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any job_post content'.
  $permissions['edit any job_post content'] = array(
    'name' => 'edit any job_post content',
    'roles' => array(
      'Editor' => 'Editor',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own job_post content'.
  $permissions['edit own job_post content'] = array(
    'name' => 'edit own job_post content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
