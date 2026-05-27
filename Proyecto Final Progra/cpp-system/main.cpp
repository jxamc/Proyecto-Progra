#include <iostream>

#include "CSVLoader.h"
#include "HashTable.h"
#include "AVL.h"
#include "Graph.h"
#include "Benchmark.h"

using namespace std;

int main() {

    HashTable hash;
    AVLTree avl;
    Graph graph;

    int option;

    do {

        cout << "\n========== MENU ==========\n";

        cout << "1. Cargar CSV\n";
        cout << "2. Mostrar estudiantes\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Estadisticas\n";
        cout << "5. Conectar estudiantes\n";
        cout << "6. Mostrar conexiones\n";
        cout << "7. BFS\n";
        cout << "8. DFS\n";
        cout << "9. Benchmark\n";
        cout << "10. Eliminar estudiante\n";
        cout << "11. Mostrar ranking AVL\n";
        cout << "12. Salir\n";

        cin >> option;

        switch(option) {

            case 1: {

                CSVLoader::loadCSV(
                    "../dataset/estudiantes.csv",
                    hash,
                    avl
                );

                break;
            }

            case 2: {

                hash.showAll();

                break;
            }

            case 3: {

                int id;

                cout << "ID: ";
                cin >> id;

                Student* s =
                    hash.search(id);

                if(s != NULL) {

                    cout << "\nNombre: "
                         << s->full_name
                         << endl;

                    cout << "Carrera: "
                         << s->career
                         << endl;

                    cout << "Semestre: "
                         << s->semester
                         << endl;

                    cout << "GPA: "
                         << s->gpa
                         << endl;

                    cout << "Skill Score: "
                         << s->skill_score
                         << endl;
                }
                else {

                    cout << "No encontrado\n";
                }

                break;
            }

            case 4: {

                hash.stats();

                cout << "Altura AVL: "
                     << avl.treeHeight()
                     << endl;

                break;
            }

            case 5: {

                int id1;
                int id2;

                cout << "ID1: ";
                cin >> id1;

                cout << "ID2: ";
                cin >> id2;

                graph.addConnection(
                    id1,
                    id2
                );

                break;
            }

            case 6: {

                int id;

                cout << "ID: ";
                cin >> id;

                graph.showConnections(id);

                break;
            }

            case 7: {

                int start;

                cout << "Inicio BFS: ";
                cin >> start;

                graph.BFS(start);

                break;
            }

            case 8: {

                int start;

                cout << "Inicio DFS: ";
                cin >> start;

                graph.DFS(start);

                break;
            }

            case 9: {

                Benchmark::run(
                    hash,
                    avl,
                    graph
                );

                break;
            }

            case 10: {

                int id;

                cout << "ID eliminar: ";
                cin >> id;

                Student* s =
                    hash.search(id);

                if(s == NULL) {

                    cout << "No existe\n";

                    break;
                }

                avl.remove(
                    s->skill_score
                );

                graph.removeStudent(id);

                hash.remove(id);

                cout << "Eliminado\n";

                break;
            }

            case 11: {

                avl.inorder();

                break;
            }

            case 12: {

                cout << "Saliendo...\n";

                break;
            }

            default: {

                cout << "Opcion invalida\n";
            }
        }

    } while(option != 12);

    return 0;
}