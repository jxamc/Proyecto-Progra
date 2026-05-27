#include "Project.h"

Project::Project(
    int id,
    string t,
    string d,
    int year
) {
    project_id = id;
    title = t;
    description = d;
    completion_year = year;

    next = NULL;
}