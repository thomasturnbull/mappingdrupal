<?php
  print "<?xml"; ?> version="1.0" encoding="utf-8" <?php print "?>";
?>

<kml xmlns="http://www.opengis.net/kml/2.2">
  <Document>
    <name><?php print $viewtitle; ?></name>
    <?php print $style ?>
    <?php print $rows ?>
  </Document>
</kml>
