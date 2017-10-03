<?php

$argv[1] = 'galleryassets';
/*
 * @param Array $types
 * @abstract Array of allowed file types
 */

if (!isset($argv[1]))
    exit("Must specify a directory to scan\n");

if (!is_dir($argv[1]))
    exit($argv[1]."' is not a directory\n");

/*
 * @name getList
 * @param Array $dir
 * @param Array $types
 * @abstract Recursively iterates over specified directory
 *           populating array based on array of file extensions
 * @return Array $files
 */
function getList($dir)
{
    $it = new RecursiveDirectoryIterator($dir);
    foreach(new RecursiveIteratorIterator($it) as $file)
    {
        $files[] = $file->__toString();
    }
    return $files;  
}

/*
 * @name getDetails
 * @param Array $dir
 * @param Array $types
 * @abstract Recursively iterates over specified directory
 *           populating array with details of each file
 * @return Array $files
 */
function getDetails($array)
{
$files = [];


$index = 0 ;
        foreach($array as $file)
        {
        
$directory = explode("/", $file);


                isset($files['jpg'][basename($file)]) ? $files['jpg'][basename($file)] : '';
                $files['jpg'][$index]['source'] = $file;
                $files['jpg'][$index]['directory'] = $directory[1];
           $index++;
        }
   
    return array('files'=>$files);
}

if (!function_exists('json_encode')) {

    /*
     * @name json_encode
     * @param Mixed $val
     * @abstract Alternate emulated json_encode function
     * @return Object $res
     */
    function json_encode($val)
    {
        if (is_string($val)) return '"'.addslashes($val).'"';
        if (is_numeric($val)) return $val;
        if ($val === null) return 'null';
        if ($val === true) return 'true';
        if ($val === false) return 'false';

        $assoc = false;
        $i = 0;
        foreach ($val as $k=>$v){
            if ($k !== $i++){
                $assoc = true;
                break;
            }
        }
        $res = array();
        foreach ($val as $k=>$v){
            $v = json_encode($v);
            if ($assoc){
                $k = '"'.addslashes($k).'"';
                $v = $k.':'.$v;
            }
            $res[] = $v;
        }
        $res = implode(',', $res);
        return ($assoc)? '{'.$res.'}' : '['.$res.']';
    }

}


function finish() {
    header("content-type:application/json");
    if ($_GET['callback']) {
        print $_GET['callback']."(";
    }
    print json_encode($GLOBALS['ret']);
    if ($_GET['callback']) {
        print ")";
    }
    exit; 
}


/* Run application */
echo json_encode(getDetails(getList($argv[1])));




