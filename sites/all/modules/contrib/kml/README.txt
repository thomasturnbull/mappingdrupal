
# KML Module

The KML module provides a Views plugin that can format nodes, users, or 
any other data source in Drupal as a KML feed, accessible by Google Earth 
or web maps like OpenLayers and Google Maps.

## Requirements

* Views

## Compatible Modules

* [OpenLayers](http://drupal.org/project/openlayers)

## Customization

KML feeds can be customized thoroughly by overriding theme functions and files
in custom themes. They cannot, however, be customized through the Drupal UI. See 
theme functions in kml.module for reference here - adding a preprocess to the 
kml_placemark and kml_style theme function will allow for behaviors like 
scaled points and more.

## Credits

* [raintonr](http://drupal.org/user/27877)
* [geodan](http://drupal.org/user/37266)
* [rsoden](http://drupal.org/user/226437)
* [tmcw](http://drupal.org/user/12664)
