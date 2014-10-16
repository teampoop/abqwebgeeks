<?php
/**
 * @file
 * isotope_example_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function isotope_example_feature_taxonomy_default_vocabularies() {
  return array(
    'isotope_sort_options' => array(
      'name' => 'Isotope sort options',
      'machine_name' => 'isotope_sort_options',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
