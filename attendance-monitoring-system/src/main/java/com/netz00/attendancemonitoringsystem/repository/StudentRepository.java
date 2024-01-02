package com.netz00.attendancemonitoringsystem.repository;

import com.netz00.attendancemonitoringsystem.domain.Student;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Repository;

import java.util.Optional;


@Repository
public interface StudentRepository extends JpaRepository<Student, Long> {

    Optional<Student> findByJmbag(@NonNull String jmbag);
}
