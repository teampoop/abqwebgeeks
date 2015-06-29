<?php
/**
 * @file views-isotope-sort-block.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>

<div class="isotope-options">
  <ul class="isotope-sort option-set clearfix" data-option-key="sortBy">
  
    <?php foreach ($rows as $id => $row): ?>
      
      <?php
        // Sanitize sort option value.
        $dataoption = trim(strip_tags(strtolower($row)));
        $dataoption = str_replace(' ', '-', $dataoption);
        $dataoption = str_replace('/', '-', $dataoption);
        $dataoption = str_replace('&amp;', '', $dataoption);
      ?>
          
      <li><a class="sortbutton" data-option-value="<?php print $dataoption; ?>" href="#sortBy=<?php print $dataoption; ?>"><?php print trim($row); ?></a></li>
      
    <?php endforeach; ?>
  
  </ul>
	<ul id="isotope-sort-direction" class="option-set clearfix" data-option-key="sortAscending">
    <li><a class="sortbutton" href="#sortAscending=true" data-option-value="true" class="selected"><?php print t('Ascending'); ?></a></li>
    <li><a class="sortbutton" href="#sortAscending=false" data-option-value="false"><?php print t('Descending');?></a></li>
  </ul>
</div>