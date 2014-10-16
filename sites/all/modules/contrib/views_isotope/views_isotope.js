(function($) {
  $(document).ready(function() {
    var $container = $('#isotope-container');
    
    $container.isotope({
    	itemSelector: '.isotope-element'
    });
    
    // Pre-select first option in option sets.
    $('.isotope-options .option-set li:first-child a').addClass('selected');
    
    var $optionSets = $('.isotope-options .option-set');
    $optionLinks = $optionSets.find('a');
  
    $optionLinks.click(function() {
      var $this = $(this);
      // Don't proceed if already selected.
      if ($this.hasClass('selected')) {
        return false;
      }
      
      var $optionSet = $this.parents('.option-set');
      $optionSet.find('.selected').removeClass('selected'); 
      
      $this.addClass('selected');
  
      var options = {},
        key = $optionSet.attr('data-option-key'),
        value = $this.attr('data-option-value');
      // Parse 'false' as false boolean.
      value = value === 'false' ? false : value;
      
      if (value && key == 'filter') {
        // Support multiple independent filter sets.
        $selectedFilters = $('.isotope-filters.option-set a.filterbutton.selected');
        
        // Strip 'all' value to ensure other selected filters are still applied correctly.
        if ($selectedFilters.length > 0)
          value = value.replace('*', '');
        
        // Compile selector based on selected filters.
        $selectedFilters.each(function(index) {
          var filter = $(this).attr('data-option-value');
          if (filter && value.indexOf(filter) == -1 && filter != '*')
            value = value + filter;
        }); 
      }
      
      options[key] = value;
      if (key === 'layoutMode' && typeof changeLayoutMode === 'function') {
        // Changes in layout modes need extra logic.
        changeLayoutMode($this, options)
      } else {
        // Otherwise, apply new options.
        $container.isotope(options);
      }
      
      return false;
    });
	});
})(jQuery);