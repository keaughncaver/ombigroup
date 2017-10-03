
    <link rel="stylesheet" href="../../ui-calendar/bower_components/fullcalendar/dist/fullcalendar.css">
    <link rel="stylesheet" href="calendarDemo.css" />

    <script src="../../ui-calendar/bower_components/jquery/dist/jquery.js"></script>

    <script src="../../ui-calendar/bower_components/angular/angular.js"></script>
    <script src="http://angular-ui.github.io/bootstrap/ui-bootstrap-tpls-0.13.0.js"></script>
    <script src="../../ui-calendar/bower_components/moment/moment.js"></script>
    <script src="../../ui-calendar/bower_components/fullcalendar/dist/fullcalendar.js"></script>
    <script src="../../ui-calendar/bower_components/fullcalendar/dist/gcal.js"></script>
    <script src="../../ui-calendar/src/calendar.js"></script>
    <script src="calendarDemo.js"></script>



<div role="main" ng-app="calendarDemoApp" id="calendar">
    <div class="container">
        <section id="directives-calendar" ng-controller="CalendarCtrl">
            <div class="well">
                <div class="row-fluid">
                    <div class="span8">
                              <div class="btn-toolbar">
                                <p class="pull-right lead">OMBI GROUP CALENDAR</p>
                                <div class="btn-group">
                                    <button class="btn " ng-click="changeView('agendaDay', 'myCalendar1')">Day</button>
                                    <button class="btn " ng-click="changeView('agendaWeek', 'myCalendar1')">Week</button>
                                    <button class="btn " ng-click="changeView('month', 'myCalendar1')">Month</button>
                                </div>
                              </div>
                            <div class="calendar" ng-model="eventSources" calendar="myCalendar1" ui-calendar="uiConfig.calendar"></div>
                    </div>
                </div>
            </div>
        </section>
    </div>
</div>
