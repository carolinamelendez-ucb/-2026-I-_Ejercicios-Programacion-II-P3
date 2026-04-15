#pragma once
#include "VectorEstudiantes.h"
#include "VectorDocentes.h"
#include "VectorCursos.h"

class UniversidadSistema
{
private:
	VectorDocentes* listaDocentes;
	VectorCursos* listaCursos;
	VectorEstudiantes* listaEstudiantes;
public:
	UniversidadSistema(int tamanioDocentes, int tamanioCursos, int tamanioEstudiantes)
	{
		this->listaCursos = new VectorCursos(tamanioCursos);
		this->listaDocentes = new VectorDocentes(tamanioDocentes);
		this->listaEstudiantes = new VectorEstudiantes(tamanioEstudiantes);

	}
	void agregarEstudiante(Estudiante* nuevoEstudiante)
	{
		Estudiante* ciEncontrado = listaEstudiantes->buscarPorCi(nuevoEstudiante->getCi());
		if (ciEncontrado == nullptr)
		{
			listaEstudiantes->agregar(nuevoEstudiante);
		}
	}
	void agregarDocente(Docente* nuevoDocente)
	{
		Docente* ciEncontrado = listaDocentes->buscarPorCi(nuevoDocente->getCi());
		if (ciEncontrado == nullptr)
		{
			listaDocentes->agregar(nuevoDocente);
		}
	}
	void agregarCurso(Curso* nuevoCurso)
	{
		Curso* codigoEncontrado = listaCursos->buscarPorCodigo(nuevoCurso->getCodigo());
		if (codigoEncontrado == nullptr)
		{
			listaCursos->agregar(nuevoCurso);
		}
	}
	void mostrarEstudiantes()
	{
		listaEstudiantes->mostrar();
	}
	void mostrarDocentes()
	{
		listaDocentes->mostrar();
	}
	void mostrarCursos()
	{
		listaCursos->mostrar();
	}
	void asignarDocente(int ciDocente, int codigoCurso)
	{
		Docente* ciEncontrado = listaDocentes->buscarPorCi(ciDocente);
		Curso* codigoEncontrado = listaCursos->buscarPorCodigo(codigoCurso);

		if (ciEncontrado != nullptr && codigoEncontrado != nullptr)
		{
			if (ciEncontrado->getAproboEntrevista())
			{
				codigoEncontrado->asignarDocente(ciEncontrado);
				cout << "Docente asignado correctamente" << endl;
			}
			else
			{
				cout << "el docenteno no aprobo la entrevista " << endl;
			}
		}
		else {
			cout << "El docente o curso no existe" << endl;
		}
	}
	void asignarEstudiantes(int ciBuscado, int codigoCurso)
	{
		Estudiante* ciEncontrado = listaEstudiantes->buscarPorCi(ciBuscado);
		Curso* codigoEncontrado = listaCursos->buscarPorCodigo(codigoCurso);
		if (ciEncontrado != nullptr && codigoEncontrado != nullptr)
		{
			if (ciEncontrado->getPagoMatricula())
			{
				codigoEncontrado->asignarEstudiantes(ciEncontrado);
				cout << "Estudiante asignado correctamente" << endl;
			}
			else
			{
				cout << "El estudiante no pago la matricula" << endl;
			}
		}
		else
		{
			cout << "El estudiante o curso no existe" << endl;
		}
	}
	void mostrarTotalRecaudado()
	{
		cout << "El total generado por la universidad es: " << listaEstudiantes->totalRecaudado() << endl;
	}
	
	void mostrarEstudinateMasPaga()
	{
		Estudiante* pagoMayor = listaEstudiantes->estudianteMasPaga();
		cout << "El estudiante que mas paga es: " << endl;
		pagoMayor->mostrar();
	}
	void mostrarDocenteMenosPaga()
	{
		Docente* salarioMenor = listaDocentes->menorSalario();
		cout << "El docente con  menor salario  es: " << endl;
		salarioMenor->mostrar();
	}
	~UniversidadSistema()
	{
		delete listaCursos;
		delete listaDocentes;
		delete listaEstudiantes;
	}


};

