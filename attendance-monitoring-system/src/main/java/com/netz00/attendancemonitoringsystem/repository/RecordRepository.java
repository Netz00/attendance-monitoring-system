package com.netz00.attendancemonitoringsystem.repository;

import com.netz00.attendancemonitoringsystem.domain.Record;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;


@Repository
public interface RecordRepository extends JpaRepository<Record, Long> {


}
