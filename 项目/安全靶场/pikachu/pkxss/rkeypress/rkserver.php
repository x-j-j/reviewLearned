<?php
header('Access-Control-Allow-Origin: *');
/**
 * Created by runner.han
 * There is nothing new under the sun
 */

//设置允许被跨域访问

include_once '../inc/config.inc.php';
include_once '../inc/mysql.inc.php';

$link = connect();

$data = $_POST['datax'];
$query = "insert keypress(data) values('$data')";
$result = mysqli_query($link, $query);
