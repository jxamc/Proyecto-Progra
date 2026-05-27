#ifndef PROJECTLIST_H
#define PROJECTLIST_H

#include "Project.h"

class ProjectList {
private:
    Project* head;

public:
    ProjectList();

    void addProject(
        int id,
        string title,
        string description,
        int year
    );

    void showProjects();

    bool projectExists(int id);

    void deleteProject(int id);
};

#endif