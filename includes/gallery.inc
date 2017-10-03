    <script src="../../calendar/bower_components/jquery/dist/jquery.js"></script>

    <script src="../../calendar/bower_components/angular/angular.js"></script>
    <script src="http://angular-ui.github.io/bootstrap/ui-bootstrap-tpls-0.13.0.js"></script>

<script>
'use strict';

var App = angular.module('PaginationApp', []);

App.controller('MainCtrl', ['$scope', '$filter', 'TypekitService', '$http', function ($scope, $filter, $http, Typekit) {


    $scope.loadData = function () {
            var response = <?php require_once("../gallery/galleryservice.php");?>;

            $scope.more = response.files.jpg.length === $scope.per_page;
            $scope.families = $scope.families.concat(response.files.jpg);
            $scope.status_bar = "Showing " + ($scope.families.length === 0 ? "0" : "1") + " to " + $filter('number')($scope.families.length) + " of " + $filter('number')(2) + " entries";
    }

    $scope.isvalidurl = function (urltotest) {
        if (urltotest.indexOf('jpg') > -1 || urltotest.indexOf('JPG') > -1 ){ 
            return true;
        } else {
            return false;
        }
    }

    $scope.isnotdub = function (urltotest){

       if (urltotest.indexOf('..') > -1 ){ 
            return false;
        } else {
            return true;
        }

    }

    $scope.show_more = function () {
        $scope.page += 1;
        $scope.loadData();
    }

    $scope.has_more = function () {
        return $scope.more;
    }

    $scope.per_page = 10;
    $scope.page = 1;
    $scope.families = [];
    $scope.more = true;
    $scope.status_bar = "";
    $scope.loadData();
}]);


App.factory('TypekitService', ['$http', function ($http) {
    return {
        getTypekits: function (url) {
            return $http.jsonp(url);
        }
    }
}]);

/** Ajax Spinner **/
angular.module('services.SharedServices', []).config(function ($httpProvider) {
    $httpProvider.responseInterceptors.push('myHttpInterceptor');
    var spinnerFunction = function (data, headersGetter) {
        $("#loading").show();
        return data;
    };
    $httpProvider.defaults.transformRequest.push(spinnerFunction);
}).factory('myHttpInterceptor', function ($q, $window) {
    return function (promise) {
        return promise.then(function (response) {
            $("#loading").hide();
            return response;
        }, function (response) {
            $("#loading").hide();
            return $q.reject(response);
        });
    };
});

/** Ajax Spinner **/


</script>



<div ng-app="PaginationApp" >


<div class="container">
    <div ng-controller="MainCtrl">




    <!-- works -->
    <section class="imgHover clearfix cs-style-3 mb40">
        <!-- works carousel -->


        <div class="owl-carousel nekoDataOwl imgHover neko-hover-1" data-neko_items="1"  data-neko_singleitem="true">
            <div >
                <div class="container">
                    <div class="row" >
                        <div ng-repeat="family in families">

<div ng-class="{'item': isnotdub(family.source) }">


                            <article class="col-md-3 mb30" ng-if="isvalidurl(family.source)">
                                <figure class="minimalBox">
                                    <img  alt="" src="{{family.source}} " class="img-responsive">
                                </figure>   
                            </article>

                            <article class="col-md-12 mb30" ng-if="!isvalidurl(family.source) && isnotdub(family.source)">
                                <figure class="minimalBox">
                                  <h2>{{family.directory}}</h2>
                                </figure>   
                            </article>

                        </div>
                        </div>
                    </div>
               
                </div>
            </div>
        </div>




    </section>
    <!-- works -->









   
    </div>
</div>

</div>
