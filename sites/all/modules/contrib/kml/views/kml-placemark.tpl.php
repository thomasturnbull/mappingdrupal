<?php
?><Placemark>
  <name>
    <![CDATA[<?php print $name ?>]]>
  </name>
  <description>
    <![CDATA[<?php print $description ?>]]>
  </description>
  <?php if ($styleUrl): ?>
  <styleUrl><?php echo $styleUrl; ?></styleUrl>
  <?php endif; ?>
  <Point>
    <coordinates><?php print $coords ?></coordinates>
  </Point>
</Placemark>
