<?php

/**
 * @file
 * Drupal Translation module Constants.
 */
/*
 * def - only defines the constant if it has not been defined previously (in local override file)
 */
if (!function_exists('def')) {

  function def($key, $val) {
    if (!defined($key)) {
      define($key, $val);
    }
  }

}

/**
 * Local Override - a local override configuration may be used by: 
 * (1) inserting variable overrides into the Drupal "sites/default/settings.php" file (recommended)
 * (2) inserting variable into a "config.php" file in The Drupal Translation module folder 
 * (3) setting the environment var 'LINGOTEK_CONFIG_PATH' to a file path elsewhere on your system
 */
$local_env_config_filepath = getenv('LINGOTEK_CONFIG_PATH');
$local_config_file = $local_env_config_filepath !== FALSE ? $local_env_config_filepath : getcwd() . '/' . drupal_get_path('module', 'lingotek') . '/config.php';
$use_local_override = file_exists($local_config_file);
if ($use_local_override) {
  include_once $local_config_file;
}

/**
 *  Config 
 * (Note: if any of the following variables 'def' variables are set prior to this, then those settings will take precedence rather than these.)
 */
if (variable_get('lingotek_use_stage_servers', FALSE)) {
  // Stage Servers
  def('LINGOTEK_GMC_SERVER', 'https://gmc.lingotek.com/cms');
  def('LINGOTEK_API_SERVER', 'http://cms.lingotek.com');
  def('LINGOTEK_BILLING_SERVER', 'https://billing-service.lingotek.com/billing-cms/account.json');
  def('LINGOTEK_AP_OAUTH_KEY', 'd944c2ae-b66e-4322-b37e-40ba0a495eb7');
  def('LINGOTEK_AP_OAUTH_SECRET', 'e4ae98ca-835b-4d9f-8faf-116ce9c69424');
}
else {
  // Production Servers
  def('LINGOTEK_GMC_SERVER', 'https://gmc.lingotek.com');
  def('LINGOTEK_API_SERVER', 'https://myaccount.lingotek.com');
  def('LINGOTEK_BILLING_SERVER', 'https://billing-service.lingotek.com/billing/account.json');
  def('LINGOTEK_AP_OAUTH_KEY', 'd944c2ae-b66e-4322-b37e-40ba0a495eb7');
  def('LINGOTEK_AP_OAUTH_SECRET', 'e4ae98ca-835b-4d9f-8faf-116ce9c69424');
}

def('LINGOTEK_DEV', variable_get('lingotek_dev', FALSE));

/**
 * Identifies a content type which has Lingotek translation enabled.
 */
define('LINGOTEK_ENABLED', 'lingotek');

/**
 * Defines the path URLs
 */
define('LINGOTEK_MENU_LANG_BASE_URL', 'admin/config/regional/lingotek');
define('LINGOTEK_MENU_MAIN_BASE_URL', 'admin/settings/lingotek');//admin/config/lingotek
define('LINGOTEK_NOTIFICATIONS_URL', 'lingotek/notify'); // notification callback URL