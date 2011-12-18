/**
 * @file
 * Main JS for Mapping Drupal Bootstrap theme.
 */

// Namespace jQuery
(function ($) {
  /**
   * Main behavior container for theme JS
   */
  Drupal.behaviors.mappingdrupalBootstrap = {
    attach: function (context, settings) {
      // Check if processed
      if ($('body.mappingdrupal-bootstrap-processed').size() == 0) {
        // Only do once.
        $('body').addClass('mappingdrupal-bootstrap-processed');

        // Alert messages
        $('.alert-message').alert();
        
        // Smooth scrolling
        $('.anchor-scroll').anchorAnimate();
      }
    }
  };


})(jQuery);