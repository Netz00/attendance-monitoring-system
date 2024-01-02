package com.netz00.attendancemonitoringsystem.repository;

import com.netz00.attendancemonitoringsystem.domain.Room;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Repository;

import java.util.Optional;


@Repository
public interface RoomRepository extends JpaRepository<Room, Long> {

    Optional<Room> findByName(@NonNull String name);
}
