<?php
/**
 * @file views-isotope-filter-block.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<div class="isotope-options">
  <ul class="isotope-filters option-set clearfix" data-option-key="filter">
  
  	<li><a href="#filter" data-option-value="*" class="selected"><?php print t('All'); ?></a></li>
    <?php foreach ( $rows as $id => $row ): ?>
      
      <?php
        // Sanitize filter value.
        $dataoption = trim(strip_tags(strtolower($row)));
        $dataoption = str_replace(' ', '-', $dataoption);
        $dataoption = str_replace('/', '-', $dataoption);
        $dataoption = str_replace('&amp;', '', $dataoption); 
      ?>
          
      <li><a class="filterbutton" data-option-value=".<?php print $dataoption; ?>" href="#filter"><?php print trim($row); ?></a></li>
			
    <?php endforeach; ?>
    
  </ul>  
</div>
