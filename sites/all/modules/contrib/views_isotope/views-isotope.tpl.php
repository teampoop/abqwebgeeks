<?php
/**
 * @file views-isotope.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
  <div id="isotope-container">
    <?php
      $looped = FALSE;
      
			$js = '(function($) { $(document).ready(function() { var $container = $(\'#isotope-container\'); $container.isotope(\'option\', { getSortData : { @sortdata } }); $container.isotope(\'updateSortData\', $(\'.isotope-element\')); }); })(jQuery);';
			$sortdata = '';
    ?>
    <?php foreach ($rows as $id => $row): ?>
      <?php
      $classlist = NULL;
      
      // Pull out isotope-filter class if it exists.
      if (strstr($row, '<div class="isotope-filter">')) {
      	// *** F I L T E R S ***
      	$filter_matches = array();
      	preg_match_all('/<div class="isotope-filter">(.*?)<\/div>/', $row, $filter_matches);
      	
      	// Build filter matches string.
      	if (is_array($filter_matches[1])) {
        	$filter_matches = implode(', ', $filter_matches[1]);
      	} else {
        	$filter_matches = isset($filter_matches[1]) ? $filter_matches[1] : NULL;
      	}
				
        if (isset($filter_matches)) {
        	if (strstr($filter_matches, ',')) {
        		// Check for commas and treat as an array for list of taxonomy terms.
        		$classes = explode(',', $filter_matches);
        		foreach ($classes as $class) {
							$class = trim(strip_tags(strtolower($class)));
							$class = str_replace(' ', '-', $class);
							$class = str_replace('/', '-', $class);
							$class = str_replace('&amp;', '', $class);
							$classlist .= ' ' . $class;
        		}
        	} else {
        		// Normalize single term.
						$class = trim(strip_tags(strtolower($filter_matches)));
						$class = str_replace(' ', '-', $class);
						$class = str_replace('/', '-', $class);
						$class = str_replace('&amp;', '', $class);
						$classlist .= ' ' . $class;
        	}
        }
        
        $row = preg_replace('/<div class="isotope-filter">(.*?)<\/div>/', '', $row);
        
        // *** S O R T I N G ***
      	if (!$looped) {
      		$sort_matches = array();
      		preg_match_all('/<div class="isotope-sort (.*?)">(.*?)<\/div>/', $row, $sort_matches);
      		
      		if (is_array($sort_matches[1])) {
      			$matches = $sort_matches[1];
      			foreach ($matches as $match) {
      				if ($sortdata != '') $sortdata .= ', ';
							$sortdata .= '\'' . $match . '\'' . ' : function($elem) { var data = $elem.find(\'.isotope-sort.' . $match . '\').text(); console.log(data); if (!isNaN(data)) { return parseInt(data); } else { return data; } }';
      			}
      		} else {
						$sortdata .= '\'' . $sort_matches[1] . '\'' . ' : function($elem) { var data = $elem.find(\'.isotope-sort.' . $sort_matches[1] . '\').text(); console.log(data); if (!isNaN(data)) { return parseInt(data); } else { return data; } }';
      		}
				}
				
				$looped = TRUE;
      }
      ?>
      <div class="isotope-element <?php print $classlist; ?>" data-category="<?php print trim($classlist); ?>">
        <?php print $row; ?>
      </div>
    <?php endforeach; ?>
    <?php
    	$js = str_replace('@sortdata', $sortdata, $js);
    	drupal_add_js($js, array(
    		'type' => 'inline',
    		'scope' => 'header',
    		'weight' => 10,
    	));
    ?>
  </div>
