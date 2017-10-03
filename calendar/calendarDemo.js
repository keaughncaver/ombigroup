/**
 * calendarDemoApp - 0.9.0
 */
var calendarDemoApp = angular.module('calendarDemoApp', ['ui.calendar', 'ui.bootstrap']);

calendarDemoApp.controller('CalendarCtrl',
   function($scope, $compile, $timeout, uiCalendarConfig) {
    var date = new Date();
    var d = date.getDate();
    var m = date.getMonth();
    var y = date.getFullYear();

    $scope.changeTo = 'Hungarian';
    /* event source that pulls from google.com */
    $scope.eventSource = {
            url: "http://www.google.com/calendar/feeds/usa__en%40holiday.calendar.google.com/public/basic",
            className: 'gcal-event',           // an option!
            currentTimezone: 'America/Chicago' // an option!
    };
    /* event source that contains custom events on the scope */
    $scope.events = [
      {title: 'Thrive Tour Nonprofit 101 - Baton Rouge, Louisiana',start: new Date(y, m, 10)},
      {title: 'Off The Field Players’ Wives Association Lunch and Learn – Chicago, Illinois (RSVP here)',start: new Date(y, m, 15)},
      {title: 'ESPY Award',start: new Date(y, m, 13)},
      {title: 'Off The Field Players’ Wives Association Lunch and Learn  - Charlotte, North Carolina (RSVP here)',start: new Date(2015, 10, 06)},
      {title: 'Community Law Day – Baton Rouge, Louisiana',start: new Date(2015, 10, 14)},
      {title: 'Entertainment Law 101: How to Break into the Music Business – Baton Rouge, Louisiana (RSVP here)',start: new Date(2015, 10, 19)},
      {title: 'Giving Gracefully Awards – San Francisco, California',start: new Date(2016, 01, 04)},
      {title: 'Super Bowl 50',start: new Date(2016, 01, 07)},
      {title: 'NFL Draft – Chicago, Illinois',start: new Date(2016, 03, 28),end: new Date(2016, 03, 31)}

    ];
    /* event source that calls a function on every view switch */
    $scope.eventsF = function (start, end, timezone, callback) {
      var s = new Date(start).getTime() / 1000;
      var e = new Date(end).getTime() / 1000;
      var m = new Date(start).getMonth();
      var events = [{title: 'Feed Me ' + m,start: s + (50000),end: s + (100000),allDay: false, className: ['customFeed']}];
      callback(events);
    };



    /* add and removes an event source of choice */
    $scope.addRemoveEventSource = function(sources,source) {
      var canAdd = 0;
      angular.forEach(sources,function(value, key){
        if(sources[key] === source){
          sources.splice(key,1);
          canAdd = 1;
        }
      });
      if(canAdd === 0){
        sources.push(source);
      }
    };


    /* Change View */
    $scope.changeView = function(view,calendar) {
      uiCalendarConfig.calendars[calendar].fullCalendar('changeView',view);
    };
    /* Change View */
    $scope.renderCalender = function(calendar) {
      $timeout(function() {
        if(uiCalendarConfig.calendars[calendar]){
          uiCalendarConfig.calendars[calendar].fullCalendar('render');
        }
      });
    };
     /* Render Tooltip */
    $scope.eventRender = function( event, element, view ) {
        element.attr({'tooltip': event.title,
                      'tooltip-append-to-body': true});
        $compile(element)($scope);
    };
    /* config object */
    $scope.uiConfig = {
      calendar:{
        height: 450,
        editable: false,
        header:{
          left: 'title',
          center: '',
          right: 'today prev,next'
        },
        eventClick: $scope.alertOnEventClick,
        eventDrop: $scope.alertOnDrop,
        eventResize: $scope.alertOnResize,
        eventRender: $scope.eventRender
      }
    };


    /* event sources array*/
    $scope.eventSources = [$scope.events, $scope.eventSource, $scope.eventsF];

});
/* EOF */
