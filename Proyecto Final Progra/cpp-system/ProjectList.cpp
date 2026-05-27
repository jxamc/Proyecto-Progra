#include "ProjectList.h"

ProjectList::ProjectList() {
    head = NULL;
}

bool ProjectList::projectExists(int id) {

    Project* temp = head;

    while(temp != NULL) {

        if(temp->project_id == id) {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

void ProjectList::addProject(
    int id,
    string title,
    string description,
    int year
) {

    if(projectExists(id)) {

        cout << "Proyecto duplicado\n";
        return;
    }

    Project* nuevo = new Project(
        id,
        title,
        description,
        year
    );

    nuevo->next = head;
    head = nuevo;

    cout << "Proyecto agregado\n";
}

void ProjectList::showProjects() {

    Project* temp = head;

    while(temp != NULL) {

        cout << "ID: "
             << temp->project_id
             << endl;

        cout << "Titulo: "
             << temp->title
             << endl;

        cout << "Descripcion: "
             << temp->description
             << endl;

        cout << "Anio: "
             << temp->completion_year
             << endl;

        cout << "------------------\n";

        temp = temp->next;
    }
}

void ProjectList::deleteProject(int id) {

    if(head == NULL) {
        return;
    }

    if(head->project_id == id) {

        Project* borrar = head;

        head = head->next;

        delete borrar;

        return;
    }

    Project* temp = head;

    while(temp->next != NULL) {

        if(temp->next->project_id == id) {

            Project* borrar = temp->next;

            temp->next = borrar->next;

            delete borrar;

            return;
        }

        temp = temp->next;
    }
}