package com.netz00.attendancemonitoringsystem.service;

import com.netz00.attendancemonitoringsystem.domain.Record;
import com.netz00.attendancemonitoringsystem.domain.Room;
import com.netz00.attendancemonitoringsystem.domain.Student;
import com.netz00.attendancemonitoringsystem.dto.PostLendingDTO;
import com.netz00.attendancemonitoringsystem.exception.ResourceNotFoundException;
import com.netz00.attendancemonitoringsystem.repository.RecordRepository;
import com.netz00.attendancemonitoringsystem.repository.RoomRepository;
import com.netz00.attendancemonitoringsystem.repository.StudentRepository;
import jakarta.transaction.Transactional;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
@Transactional
public class RecordService {

    private final RecordRepository recordRepository;
    private final StudentRepository studentRepository;
    private final RoomRepository roomRepository;

    @Autowired
    public RecordService(RecordRepository recordRepository, StudentRepository studentRepository, RoomRepository roomRepository) {
        this.recordRepository = recordRepository;
        this.studentRepository = studentRepository;
        this.roomRepository = roomRepository;

    }

    public Record addRecord(PostLendingDTO postLendingDTO) {

        Student student = studentRepository.findByJmbag(postLendingDTO.getStudentJmbag()).orElseThrow(() -> new ResourceNotFoundException("Student with JMBAG " + postLendingDTO.getStudentJmbag() + " does not exist."));
        Room room = roomRepository.findByName(postLendingDTO.getRoomName()).orElseThrow(() -> new ResourceNotFoundException("Room with name " + postLendingDTO.getRoomName() + " does not exist."));

        Record record = new Record();
        record.setRoom(room);
        record.setStudent(student);

        return recordRepository.save(record);

    }
}
