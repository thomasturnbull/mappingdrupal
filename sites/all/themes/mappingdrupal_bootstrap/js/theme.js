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
        
        // Welcome message closer
        var $closer = $('<div class="closer-open">x</div>');
        $closer.toggle(
          function() {
            $('.welcome-message').slideUp();
            $(this).html(Drupal.t('welcome'));
          },
          function() {
            $('.welcome-message').slideDown();
            $(this).html('x');
          }
        );
        $('.fullscreen').append($closer);
        
        // Masonry
        var $container = $('.masonry-container');
        if ($container.size() > 0) {
          $container.imagesLoaded(function(){
            $container.masonry({
              itemSelector: '.block',
              columnWidth: 320
            });
          });
        }
        
        // SVG icons
        if (typeof svgIcons != 'undefined') {
          var style = {
            fill: "#BFBFBF",
            stroke: "none"
          };
          var animate = {
            fill: "#404040",
            stroke: "none"
          };
          
          for (var i in svgIcons) {
            $('.' + i).each(function() {
              $(this).html('');
              var ico = Raphael(this, 32, 32).path(svgIcons[i]).attr(style).scale(.5, .5);
              ico.hover(
                function() {
                  ico.attr(animate);
                },
                function() {
                  ico.attr(style);
                }
              );
            });
          }
        }
      }
    }
  };


})(jQuery);